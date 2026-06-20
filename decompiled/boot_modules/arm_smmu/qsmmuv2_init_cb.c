__int64 __fastcall qsmmuv2_init_cb(__int64 *a1)
{
  __int64 v2; // x0
  __int64 (__fastcall **v3)(__int64 *); // x20
  __int64 v4; // x8
  void (*v5)(void); // x8
  __int64 (__fastcall *v6)(__int64 *); // x8

  v2 = *a1;
  v3 = (__int64 (__fastcall **)(__int64 *))a1[5];
  v4 = *(_QWORD *)(v2 + 48);
  if ( v4 && (v5 = *(void (**)(void))(v4 + 8)) != nullptr )
  {
    if ( *((_DWORD *)v5 - 1) != -1008624849 )
      __break(0x8228u);
    v5();
  }
  else
  {
    writel_relaxed_1(
      0x70000000u,
      (unsigned int *)(*(_QWORD *)(v2 + 8)
                     + ((*(_DWORD *)(v2 + 24) + *((unsigned __int8 *)a1 + 48)) << *(_DWORD *)(v2 + 28))
                     + 4LL));
  }
  v6 = *v3;
  if ( *((_DWORD *)*v3 - 1) != 251140989 )
    __break(0x8228u);
  return v6(a1);
}
