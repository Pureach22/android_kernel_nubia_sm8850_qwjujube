__int64 __fastcall lim_send_edca_params(__int64 a1, int *a2, __int16 a3, char a4)
{
  __int64 v8; // x0
  double v9; // d0
  double v10; // d1
  double v11; // d2
  double v12; // d3
  double v13; // d4
  double v14; // d5
  double v15; // d6
  double v16; // d7
  int v17; // w9
  int v18; // w9
  int v19; // w9
  int v20; // w10
  __int64 v21; // x20
  unsigned int v22; // w19
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  _DWORD v32[2]; // [xsp+8h] [xbp-38h] BYREF
  __int64 v33; // [xsp+10h] [xbp-30h]
  __int64 v34; // [xsp+18h] [xbp-28h]
  __int64 v35; // [xsp+20h] [xbp-20h]
  __int64 v36; // [xsp+28h] [xbp-18h]
  __int64 v37; // [xsp+30h] [xbp-10h]
  __int64 v38; // [xsp+38h] [xbp-8h]

  v38 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v8 = _qdf_mem_malloc(0x18u, "lim_send_edca_params", 165);
  if ( v8 )
  {
    *(_WORD *)v8 = a3;
    v17 = *a2;
    *(_BYTE *)(v8 + 6) = *((_BYTE *)a2 + 4);
    *(_DWORD *)(v8 + 2) = v17;
    v18 = *(int *)((char *)a2 + 5);
    *(_BYTE *)(v8 + 11) = *((_BYTE *)a2 + 9);
    *(_DWORD *)(v8 + 7) = v18;
    v19 = *(int *)((char *)a2 + 10);
    *(_BYTE *)(v8 + 16) = *((_BYTE *)a2 + 14);
    *(_DWORD *)(v8 + 12) = v19;
    LOBYTE(v19) = *((_BYTE *)a2 + 19);
    v20 = *(int *)((char *)a2 + 15);
    v33 = v8;
    *(_BYTE *)(v8 + 22) = a4 & 1;
    v21 = v8;
    *(_BYTE *)(v8 + 21) = v19;
    *(_DWORD *)(v8 + 17) = v20;
    v32[0] = 4150;
    v32[1] = 0;
    qdf_trace_msg(
      0x35u,
      8u,
      "%s: Sending WMA_UPDATE_EDCA_PROFILE_IND",
      v9,
      v10,
      v11,
      v12,
      v13,
      v14,
      v15,
      v16,
      "lim_send_edca_params");
    mac_trace_msg_tx(a1, 255, 4150);
    v22 = wma_post_ctrl_msg(a1, v32);
    if ( v22 )
    {
      _qdf_mem_free(v21);
      qdf_trace_msg(
        0x35u,
        2u,
        "%s: Posting WMA_UPDATE_EDCA_PROFILE_IND failed, reason=%X",
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        v30,
        "lim_send_edca_params",
        v22);
    }
  }
  else
  {
    v22 = 2;
  }
  _ReadStatusReg(SP_EL0);
  return v22;
}
