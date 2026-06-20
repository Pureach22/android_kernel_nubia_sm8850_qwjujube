__int64 __fastcall aead_aes_fb_stage2_ahash_complete(_QWORD *a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  __int64 v6; // x0
  __int64 v7; // x0
  _DWORD *v8; // x8

  if ( !a2 )
    scatterwalk_map_and_copy(
      a1 + 31,
      a1[55],
      *(unsigned int *)(a1[29] + 52LL),
      *(unsigned int *)(*(_QWORD *)(a1[29] + 32LL) + 220LL),
      1);
  v4 = a1[53];
  v5 = a1[29];
  if ( v4 )
    kfree_sensitive(v4);
  v6 = a1[30];
  if ( v6 )
    kfree_sensitive(v6);
  v7 = a1[51];
  a1[53] = 0;
  a1[30] = 0;
  kfree(v7);
  v8 = *(_DWORD **)(v5 + 16);
  if ( *(v8 - 1) != 1607364836 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, _QWORD))v8)(v5, a2);
}
