__int64 __fastcall ufs_qcom_ice_program_key(__int64 a1, __int64 a2, unsigned int a3)
{
  unsigned __int8 *v3; // x8
  int v4; // w9
  int v5; // w8
  bool v6; // zf
  __int64 v8; // x0

  if ( !a1 )
  {
    __break(0x800u);
    JUMPOUT(0x11740);
  }
  v3 = (unsigned __int8 *)(*(_QWORD *)(a1 + 4528) + 4LL * *(unsigned __int8 *)(a2 + 65));
  v4 = *v3;
  v5 = v3[2];
  if ( v4 )
    v6 = 0;
  else
    v6 = v5 == 3;
  if ( !v6 )
    return 4294967201LL;
  v8 = *(_QWORD *)(*(_QWORD *)(a1 + 184) + 152LL);
  if ( *(char *)(a2 + 67) < 0 )
    return qcom_ice_program_key(v8, 0, 3, a2, *(unsigned __int8 *)(a2 + 64), a3);
  else
    return qcom_ice_evict_key(v8, a3);
}
