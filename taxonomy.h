#ifndef TAXONOMY_H
#define TAXONOMY_H

#ifdef __cplusplus
extern "C" {
#endif

enum taxonomy_category {
	NONE,
	OCEAN,
	COUNTRY,
	ADMIN_L1,
	ADMIN_L2,
	LOCALNAME,
	NR_CATEGORIES
};

extern char *taxonomy_category_names[NR_CATEGORIES];
extern char *taxonomy_api_names[NR_CATEGORIES];

struct taxonomy {
	int category;		/* the category for this tag: ocean, country, admin_l1, admin_l2, localname, etc */
	const char *value;	/* the value returned, parsed, or manually entered for that category */
	enum { GEOCODED, PARSED, MANUAL } origin;
};

/* the data block contains 3 taxonomy structures - unused ones have a tag value of NONE */
struct taxonomy_data {
	int nr;
	struct taxonomy *category;
};

struct taxonomy *alloc_taxonomy();
void free_taxonomy(struct taxonomy *t);

#ifdef __cplusplus
}
#endif
#endif // TAXONOMY_H