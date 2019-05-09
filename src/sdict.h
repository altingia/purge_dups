#ifndef SDICT_H
#define SDICT_H

#include <stdint.h>

typedef struct {
	char *name, *seq;
	uint32_t len, aux:26, type:3, isq:1, del:1, del2:1;
	uint32_t best_hit;
} sd_seq_t;

typedef struct {
	uint32_t n_seq, m_seq;
	sd_seq_t *seq;
	void *h;
} sdict_t;

#ifdef __cplusplus
extern "C" {
#endif

sdict_t *sd_init(void);
void sd_destroy(sdict_t *d);
int32_t sd_put(sdict_t *d, const char *name, char *seq, uint32_t len, uint32_t isq);
int32_t sd_put2(sdict_t *d, const char *name, uint32_t len, uint32_t le, uint32_t rs, uint32_t l_snp_n, uint32_t r_snp_n);
int32_t sd_get(const sdict_t *d, const char *name);
int32_t *sd_squeeze(sdict_t *d);

#ifdef __cplusplus
}
#endif

#endif