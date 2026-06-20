__int64 __fastcall wlan_serialization_request(
        unsigned int *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 psoc_from_cmd; // x0
  __int64 psoc_obj; // x0
  __int64 v12; // x20
  __int64 v13; // x21
  __int64 v14; // x22
  void (__fastcall *v15)(__int64, int *, unsigned int *); // x8
  __int64 v16; // x0
  __int64 v17; // x8
  _DWORD *v18; // x8
  __int64 result; // x0
  const char *v20; // x2
  int v21; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v22; // [xsp+8h] [xbp-8h]

  v22 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  if ( !a1 )
  {
    v20 = "%s: serialization cmd is null";
LABEL_18:
    qdf_trace_msg(0x4Cu, 2u, v20, a2, a3, a4, a5, a6, a7, a8, a9, "wlan_serialization_request");
    goto LABEL_19;
  }
  if ( (unsigned int)wlan_serialization_validate_cmd(a1[4], *a1) )
  {
LABEL_19:
    result = 6;
    goto LABEL_20;
  }
  psoc_from_cmd = wlan_serialization_get_psoc_from_cmd(a1);
  if ( !psoc_from_cmd )
  {
    v20 = "%s: psoc _obj is invalid";
    goto LABEL_18;
  }
  psoc_obj = wlan_serialization_get_psoc_obj(psoc_from_cmd);
  if ( !psoc_obj )
  {
    v20 = "%s: ser_soc_obj is invalid";
    goto LABEL_18;
  }
  v12 = psoc_obj;
  v13 = 0;
  v14 = psoc_obj + 14688;
  do
  {
    if ( *a1 >= 0x22 )
LABEL_24:
      __break(0x5512u);
    v15 = *(void (__fastcall **)(__int64, int *, unsigned int *))(v12 + 432LL * *a1 + 8 * v13);
    if ( v15 )
    {
      v16 = *((_QWORD *)a1 + 4);
      if ( *((_DWORD *)v15 - 1) != -271582013 )
        __break(0x8228u);
      v15(v16, &v21, a1);
      v17 = *a1;
      if ( (unsigned int)v17 > 0x21 )
        goto LABEL_24;
      v18 = *(_DWORD **)(v14 + 8 * v17);
      if ( v18 )
      {
        if ( *(v18 - 1) != -201266319 )
          __break(0x8228u);
        if ( (((__int64 (__fastcall *)(int *, _QWORD))v18)(&v21, (unsigned int)v13) & 1) == 0 )
        {
          result = 2;
          goto LABEL_20;
        }
      }
    }
    ++v13;
  }
  while ( v13 != 54 );
  result = wlan_serialization_enqueue_cmd(a1, 0);
LABEL_20:
  _ReadStatusReg(SP_EL0);
  return result;
}
