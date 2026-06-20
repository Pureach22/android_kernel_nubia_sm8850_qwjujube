void __noreturn sub_8270()
{
  unsigned int *v0; // x9
  unsigned int *v1; // x10
  unsigned int *v2; // x9
  unsigned int *v3; // x9
  unsigned int *v4; // x9
  unsigned int *v5; // x9
  unsigned int *v6; // x9
  unsigned int *v7; // x9
  unsigned int *v8; // x9
  unsigned int *v9; // x9

  v2 = (unsigned int *)atomic_load(v0);
  v3 = (unsigned int *)atomic_load(v2);
  v4 = (unsigned int *)atomic_load(v3);
  v5 = (unsigned int *)atomic_load(v4);
  v6 = (unsigned int *)atomic_load(v5);
  atomic_load(v1);
  v7 = (unsigned int *)atomic_load(v6);
  atomic_load(v7);
  atomic_load(v7);
  v8 = (unsigned int *)atomic_load(v7);
  v9 = (unsigned int *)atomic_load(v8);
  atomic_load(v9);
  JUMPOUT(0x82A0);
}
