#ifndef __MINODEEXPIRE_H
#define __MINODEEXPIRE_H

typedef struct {
  inodeno_t ino;
  int nonce;
  int from;
} MInodeExpire_st;

class MInodeExpire : public Message {
  MInodeExpire_st st;

 public:
  inodeno_t get_ino() { return st.ino; }
  int get_from() { return st.from; }
  int get_nonce() { return st.nonce; }

  MInodeExpire() {}
  MInodeExpire(inodeno_t ino, int from, int nonce) :
	Message(MSG_MDS_INODEEXPIRE) {
	st.ino = ino;
	st.from = from;
	st.nonce = nonce;
  }
  virtual char *get_type_name() { return "InEx";}
  
  virtual int decode_payload(crope s) {
	s.copy(0, sizeof(st), (char*)&st);
  }
  virtual crope get_payload() {
	crope s;
	s.append((char*)&st,sizeof(st));
	return s;
  }
};

#endif
