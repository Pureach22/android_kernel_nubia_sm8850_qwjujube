__int64 __fastcall lim_ft_send_aggr_qos_rsp(__int64 a1, __int16 *a2, unsigned int a3)
{
  __int64 result; // x0
  __int16 v7; // w8
  __int64 v8; // x8
  __int64 v9; // x11
  __int64 v10; // x12
  __int64 v11; // x9
  __int64 v12; // x12
  __int64 v13; // x11
  __int64 v14; // x9
  __int64 v15; // x10
  __int64 v16; // x11
  __int64 v17; // x9
  __int64 v18; // x10
  __int64 v19; // x11
  __int64 v20; // x10
  __int64 v21; // x11
  __int64 v22; // x12
  __int64 v23; // x10
  __int64 v24; // x11
  __int64 v25; // x12
  __int64 v26; // x8
  __int64 v27; // x11
  __int64 v28; // x12
  __int64 v29; // x10
  __int64 v30; // x11
  __int64 v31; // x12

  result = _qdf_mem_malloc(0x2FCu, "lim_ft_send_aggr_qos_rsp", 866);
  if ( result )
  {
    *(_BYTE *)(result + 4) = a3;
    *(_DWORD *)result = 50074677;
    v7 = *a2;
    *(_WORD *)(result + 8) = *a2;
    if ( (v7 & 1) != 0 )
    {
      *(_DWORD *)(result + 16) = *((_DWORD *)a2 + 59) != 0;
      v14 = *(_QWORD *)(a2 + 9);
      v15 = *(_QWORD *)(a2 + 1);
      v16 = *(_QWORD *)(a2 + 5);
      *(_QWORD *)(result + 50) = *(_QWORD *)(a2 + 13);
      *(_QWORD *)(result + 42) = v14;
      *(_QWORD *)(result + 34) = v16;
      *(_QWORD *)(result + 26) = v15;
      v17 = *(_QWORD *)(a2 + 25);
      v18 = *(_QWORD *)(a2 + 17);
      v19 = *(_QWORD *)(a2 + 21);
      *(_WORD *)(result + 82) = a2[29];
      *(_QWORD *)(result + 74) = v17;
      *(_QWORD *)(result + 66) = v19;
      *(_QWORD *)(result + 58) = v18;
      v7 = *a2;
      if ( (*a2 & 2) == 0 )
      {
LABEL_4:
        if ( (v7 & 4) == 0 )
          goto LABEL_5;
        goto LABEL_11;
      }
    }
    else if ( (v7 & 2) == 0 )
    {
      goto LABEL_4;
    }
    *(_DWORD *)(result + 204) = *((_DWORD *)a2 + 60) != 0;
    v20 = *(_QWORD *)(a2 + 34);
    v21 = *(_QWORD *)(a2 + 42);
    v22 = *(_QWORD *)(a2 + 38);
    *(_QWORD *)(result + 214) = *(_QWORD *)(a2 + 30);
    *(_QWORD *)(result + 230) = v22;
    *(_QWORD *)(result + 238) = v21;
    *(_QWORD *)(result + 222) = v20;
    v23 = *(_QWORD *)(a2 + 54);
    v24 = *(_QWORD *)(a2 + 46);
    v25 = *(_QWORD *)(a2 + 50);
    *(_WORD *)(result + 270) = a2[58];
    *(_QWORD *)(result + 254) = v25;
    *(_QWORD *)(result + 262) = v23;
    *(_QWORD *)(result + 246) = v24;
    v7 = *a2;
    if ( (*a2 & 4) == 0 )
    {
LABEL_5:
      if ( (v7 & 8) == 0 )
        return lim_send_sme_aggr_qos_rsp(a1, result, a3);
LABEL_6:
      *(_DWORD *)(result + 580) = *((_DWORD *)a2 + 62) != 0;
      v8 = *((_QWORD *)a2 + 25);
      v9 = *((_QWORD *)a2 + 22);
      v10 = *((_QWORD *)a2 + 23);
      *(_QWORD *)(result + 606) = *((_QWORD *)a2 + 24);
      *(_QWORD *)(result + 614) = v8;
      *(_QWORD *)(result + 590) = v9;
      *(_QWORD *)(result + 598) = v10;
      v12 = *((_QWORD *)a2 + 27);
      v11 = *((_QWORD *)a2 + 28);
      v13 = *((_QWORD *)a2 + 26);
      *(_WORD *)(result + 646) = a2[116];
      *(_QWORD *)(result + 630) = v12;
      *(_QWORD *)(result + 638) = v11;
      *(_QWORD *)(result + 622) = v13;
      return lim_send_sme_aggr_qos_rsp(a1, result, a3);
    }
LABEL_11:
    *(_DWORD *)(result + 392) = *((_DWORD *)a2 + 61) != 0;
    v26 = *(_QWORD *)(a2 + 71);
    v27 = *(_QWORD *)(a2 + 59);
    v28 = *(_QWORD *)(a2 + 63);
    *(_QWORD *)(result + 418) = *(_QWORD *)(a2 + 67);
    *(_QWORD *)(result + 426) = v26;
    *(_QWORD *)(result + 402) = v27;
    *(_QWORD *)(result + 410) = v28;
    v29 = *(_QWORD *)(a2 + 83);
    v30 = *(_QWORD *)(a2 + 75);
    v31 = *(_QWORD *)(a2 + 79);
    *(_WORD *)(result + 458) = a2[87];
    *(_QWORD *)(result + 442) = v31;
    *(_QWORD *)(result + 450) = v29;
    *(_QWORD *)(result + 434) = v30;
    if ( (*a2 & 8) == 0 )
      return lim_send_sme_aggr_qos_rsp(a1, result, a3);
    goto LABEL_6;
  }
  return result;
}
