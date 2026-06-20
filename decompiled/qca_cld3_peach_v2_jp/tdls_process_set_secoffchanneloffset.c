__int64 __fastcall tdls_process_set_secoffchanneloffset(__int64 a1)
{
  __int64 v2; // x0
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  unsigned int v11; // w20
  void (__fastcall *v12)(_QWORD); // x8
  __int64 v13; // x0
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v16[2]; // [xsp+10h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)a1;
  v15 = 0;
  v16[0] = 0;
  if ( (unsigned int)tdls_get_vdev_objects(v2, v16, &v15) )
  {
    v11 = -524;
    v12 = *(void (__fastcall **)(_QWORD))(a1 + 16);
    if ( !v12 )
      goto LABEL_6;
  }
  else
  {
    qdf_trace_msg(
      0,
      8u,
      "%s: TDLS offchannel offset to be configured %d",
      v3,
      v4,
      v5,
      v6,
      v7,
      v8,
      v9,
      v10,
      "tdls_process_set_secoffchanneloffset",
      *(unsigned int *)(a1 + 8));
    v11 = tdls_set_tdls_secoffchanneloffset(v15, *(unsigned int *)(a1 + 8));
    v12 = *(void (__fastcall **)(_QWORD))(a1 + 16);
    if ( !v12 )
      goto LABEL_6;
  }
  v13 = *(_QWORD *)a1;
  if ( *((_DWORD *)v12 - 1) != 1458356883 )
    __break(0x8228u);
  v12(v13);
LABEL_6:
  _qdf_mem_free(a1);
  _ReadStatusReg(SP_EL0);
  return v11;
}
