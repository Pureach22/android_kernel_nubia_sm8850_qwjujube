void __noreturn sub_AFF0()
{
  unsigned int *v0; // x9
  unsigned int *v1; // x10
  unsigned int *v2; // x12
  unsigned int *v3; // x19
  unsigned int *v4; // x10
  unsigned int *v5; // x9
  unsigned int *v6; // x8
  unsigned int *v7; // x8
  unsigned int *v8; // x8
  unsigned int *v9; // x8
  unsigned int *v10; // x12

  v4 = (unsigned int *)atomic_load(v1);
  atomic_load(v4);
  v5 = (unsigned int *)atomic_load(v0);
  v6 = (unsigned int *)atomic_load(v3);
  v7 = (unsigned int *)atomic_load(v6);
  v8 = (unsigned int *)atomic_load(v7);
  v9 = (unsigned int *)atomic_load(v8);
  atomic_load(v9);
  atomic_load(v5);
  v10 = (unsigned int *)atomic_load(v2);
  atomic_load(v10);
  JUMPOUT(0xB01C);
}
