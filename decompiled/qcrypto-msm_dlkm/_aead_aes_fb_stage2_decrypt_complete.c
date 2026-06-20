__int64 __fastcall aead_aes_fb_stage2_decrypt_complete(_QWORD *a1, unsigned int a2)
{
  __int64 v3; // x0
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x0
  _DWORD *v8; // x8

  v3 = a1[53];
  v5 = a1[29];
  if ( v3 )
    kfree_sensitive(v3);
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
