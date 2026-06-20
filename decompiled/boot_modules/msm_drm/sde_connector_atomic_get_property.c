__int64 __fastcall sde_connector_atomic_get_property(__int64 a1, __int64 a2, __int64 a3, _QWORD *a4)
{
  unsigned int v8; // w22
  __int64 result; // x0
  _DWORD *v10; // x8
  __int64 v11; // x4

  if ( !a1 || !a2 )
  {
    printk(&unk_27A84E, "sde_connector_atomic_get_property");
    return 4294967274LL;
  }
  v8 = msm_property_index(a1 + 3312, a3);
  if ( v8 == 12 )
  {
    result = 0;
    *a4 = -1;
    v10 = *(_DWORD **)(a1 + 2936);
    if ( !v10 )
      return result;
  }
  else
  {
    result = msm_property_atomic_get(a1 + 3312, a2 + 448, a3, a4);
    v10 = *(_DWORD **)(a1 + 2936);
    if ( !v10 )
      return result;
  }
  v11 = *(_QWORD *)(a1 + 2760);
  if ( *(v10 - 1) != -328737945 )
    __break(0x8228u);
  return ((__int64 (__fastcall *)(__int64, __int64, _QWORD, _QWORD *, __int64))v10)(a1, a2, v8, a4, v11);
}
