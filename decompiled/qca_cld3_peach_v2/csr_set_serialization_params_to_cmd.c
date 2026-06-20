__int64 __fastcall csr_set_serialization_params_to_cmd(
        __int64 a1,
        _DWORD *a2,
        int *a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  int v12; // w9
  int v13; // w8
  int v14; // w8
  const char *v15; // x2
  int v16; // w8
  __int64 v20; // x0
  int v21; // w9
  unsigned int v22; // w9
  int v23; // w9
  __int64 v24; // x4
  const char *v25; // x2
  char v26; // w10
  int v29; // w8
  unsigned int v35; // w8
  unsigned int v36; // w8

  if ( !a2 )
  {
    v15 = "%s: Invalid sme_cmd";
LABEL_12:
    qdf_trace_msg(0x34u, 2u, v15, a5, a6, a7, a8, a9, a10, a11, a12, "csr_set_serialization_params_to_cmd");
    return 16;
  }
  if ( !a3 )
  {
    v15 = "%s: Invalid serialization_cmd";
    goto LABEL_12;
  }
  _X9 = (unsigned int *)(a1 + 21616);
  __asm { PRFM            #0x11, [X9] }
  do
  {
    v35 = __ldxr(_X9);
    v36 = v35 + 1;
  }
  while ( __stlxr(v36, _X9) );
  __dmb(0xBu);
  v12 = v36 & 0xFFFFFF | 0xD000000;
  a2[5] = v12;
  a3[1] = v12;
  v13 = a2[4];
  if ( v13 > 262146 )
  {
    if ( v13 <= 262148 )
    {
      if ( v13 == 262147 )
        v14 = 16;
      else
        v14 = 17;
      goto LABEL_27;
    }
    switch ( v13 )
    {
      case 262149:
        v14 = 18;
        goto LABEL_27;
      case 262150:
        v14 = 19;
        goto LABEL_27;
      case 262151:
        v14 = 31;
LABEL_27:
        *a3 = v14;
        goto LABEL_28;
    }
LABEL_34:
    *a3 = 34;
    goto LABEL_39;
  }
  if ( v13 > 0x40000 )
  {
    if ( v13 == 262145 )
      v14 = 11;
    else
      v14 = 12;
    goto LABEL_27;
  }
  if ( v13 != 65537 )
  {
    if ( v13 == 65538 )
    {
      v14 = 5;
      goto LABEL_27;
    }
    goto LABEL_34;
  }
  v16 = a2[8];
  if ( v16 == 1 )
  {
    v14 = 2;
    goto LABEL_27;
  }
  _ZF = v16 == 2;
  if ( v16 == 2 )
    v29 = 3;
  else
    v29 = 34;
  *a3 = v29;
  if ( !_ZF )
  {
LABEL_39:
    v24 = (unsigned int)a2[4];
    v25 = "%s: serialization enum not found for sme_cmd type %d";
    goto LABEL_40;
  }
LABEL_28:
  v20 = ((__int64 (__fastcall *)(_QWORD, _QWORD, __int64))wlan_objmgr_get_vdev_by_id_from_psoc)(
          *(_QWORD *)(a1 + 21624),
          (unsigned int)a2[6],
          11);
  *((_QWORD *)a3 + 4) = v20;
  if ( !v20 )
  {
    v24 = (unsigned int)a2[6];
    v25 = "%s: vdev is NULL for vdev_id:%d";
LABEL_40:
    qdf_trace_msg(0x34u, 2u, v25, a5, a6, a7, a8, a9, a10, a11, a12, "csr_set_serialization_params_to_cmd", v24);
    return 16;
  }
  v21 = *a3;
  *((_QWORD *)a3 + 5) = a2;
  v22 = v21 - 2;
  if ( v22 > 0x1D )
    v23 = 30000;
  else
    v23 = dword_B09688[v22];
  v26 = *((_BYTE *)a3 + 20);
  a3[6] = v23;
  a3[4] = 0;
  *((_QWORD *)a3 + 1) = sme_ser_cmd_callback;
  *((_BYTE *)a3 + 20) = v26 & 0xFC | a4 & 1 | 2;
  return 0;
}
