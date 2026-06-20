__int64 __fastcall dp_sim_register_hpd(__int64 a1, _DWORD *a2, __int64 a3)
{
  int v3; // w9

  v3 = *(unsigned __int8 *)(a1 + 2276);
  *(_QWORD *)(a1 + 64) = a3;
  *(_QWORD *)(a1 + 72) = a2;
  if ( v3 == 1 )
  {
    if ( *(a2 - 1) != -121262737 )
      __break(0x8228u);
    ((void (__fastcall *)(__int64, __int64, _QWORD))a2)(a3, 1, 0);
  }
  return 0;
}
