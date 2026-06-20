__int64 __fastcall sub_36ECB0(__int64 a1, __int64 a2, __int64 a3)
{
  char v3; // zf
  __int64 v4; // x19
  __int64 v5; // x20
  __int64 v6; // x21
  __int64 v7; // x22
  _QWORD *v8; // x23
  __int64 v9; // x24
  __int64 v10; // x21
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v19; // x0

  if ( v3 )
    JUMPOUT(0x36F058);
  *(_QWORD *)(a3 + 8) = v4;
  *(_QWORD *)v4 = a3;
  *(_QWORD *)(v4 + 8) = v8;
  *v8 = v4;
  mutex_unlock(v5 + 1832);
  v10 = (unsigned int)sme_qos_setup_req(
                        v7,
                        *(unsigned __int8 *)(*(_QWORD *)(v5 + 52824) + 8LL),
                        v6,
                        hdd_wmm_sme_callback,
                        v4,
                        *(unsigned int *)(v6 + 8),
                        v9);
  v19 = qdf_trace_msg(
          0x33u,
          8u,
          "%s: sme_qos_setup_req returned %d flowid %d",
          v11,
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          "hdd_wmm_addts",
          v10,
          *(unsigned int *)(v4 + 20));
  if ( (int)v10 > 3 )
  {
    if ( (int)v10 > 6 )
      JUMPOUT(0x36EDC4);
    if ( (_DWORD)v10 == 4 )
      JUMPOUT(0x36EE40);
    if ( (_DWORD)v10 == 5 )
      JUMPOUT(0x36EDE0);
    goto LABEL_16;
  }
  if ( (_DWORD)v10 == 1 )
    JUMPOUT(0x36EDDC);
  if ( (_DWORD)v10 == 2 )
    JUMPOUT(0x36EE88);
  if ( (_DWORD)v10 != 3 )
LABEL_16:
    JUMPOUT(0x36EDF8);
  if ( *(_DWORD *)(v4 + 32) >= 5u )
    JUMPOUT(0x36F068);
  return sub_36ED6C(v19);
}
