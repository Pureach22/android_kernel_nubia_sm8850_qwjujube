__int64 __fastcall os_if_qmi_wfds_send_config_msg(int *a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v4; // x0
  int v5; // w8
  __int64 v6; // x20
  unsigned int v7; // w21
  unsigned int v8; // w10
  int v9; // w10
  int v10; // w11
  int v11; // w10
  unsigned int v12; // w10
  int v13; // w10
  int v14; // w9
  unsigned int v15; // w8
  int v16; // w8
  int v17; // w9
  int v18; // w8
  int v19; // w8
  int v20; // w9
  int v21; // w8
  unsigned int v22; // w0
  double v23; // d0
  double v24; // d1
  double v25; // d2
  double v26; // d3
  double v27; // d4
  double v28; // d5
  double v29; // d6
  double v30; // d7
  const char *v31; // x2
  unsigned int v32; // w0
  double v33; // d0
  double v34; // d1
  double v35; // d2
  double v36; // d3
  double v37; // d4
  double v38; // d5
  double v39; // d6
  double v40; // d7
  __int64 v42; // [xsp+0h] [xbp-50h] BYREF
  __int64 v43; // [xsp+8h] [xbp-48h]
  __int64 v44; // [xsp+10h] [xbp-40h]
  __int64 v45; // [xsp+18h] [xbp-38h]
  __int64 v46; // [xsp+20h] [xbp-30h]
  __int64 v47; // [xsp+28h] [xbp-28h]
  __int64 v48; // [xsp+30h] [xbp-20h]
  __int64 v49; // [xsp+38h] [xbp-18h]
  __int64 v50; // [xsp+40h] [xbp-10h]
  __int64 v51; // [xsp+48h] [xbp-8h]

  v51 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v49 = 0;
  v50 = 0;
  v47 = 0;
  v48 = 0;
  v45 = 0;
  v46 = 0;
  v43 = 0;
  v44 = 0;
  v42 = 0;
  v2 = _qdf_mem_malloc(0x150u, "os_if_qmi_wfds_send_config_msg", 83);
  if ( v2 )
  {
    v3 = v2;
    v4 = _qdf_mem_malloc(4u, "os_if_qmi_wfds_send_config_msg", 87);
    if ( v4 )
    {
      v5 = *a1;
      v6 = v4;
      if ( (unsigned int)*a1 <= 3 )
      {
        *(_DWORD *)v3 = v5;
        if ( v5 )
        {
          *(_BYTE *)(v3 + 8) = *((_BYTE *)a1 + 8);
          v8 = a1[3];
          if ( v8 >= 3 )
            v8 = 0x7FFFFFFF;
          *(_DWORD *)(v3 + 12) = v8;
          *(_BYTE *)(v3 + 16) = *((_BYTE *)a1 + 16);
          v9 = a1[5];
          if ( v9 == 1 )
            v10 = 1;
          else
            v10 = 0x7FFFFFFF;
          if ( v9 )
            v11 = v10;
          else
            v11 = 0;
          *(_DWORD *)(v3 + 20) = v11;
          *(_DWORD *)(v3 + 24) = a1[6];
          *(_DWORD *)(v3 + 28) = a1[7];
          *(_QWORD *)(v3 + 32) = *((_QWORD *)a1 + 4);
          *(_QWORD *)(v3 + 40) = *((_QWORD *)a1 + 5);
          *(_QWORD *)(v3 + 48) = *((_QWORD *)a1 + 6);
          if ( v5 != 1 )
          {
            *(_BYTE *)(v3 + 56) = *((_BYTE *)a1 + 56);
            v12 = a1[15];
            if ( v12 >= 3 )
              v12 = 0x7FFFFFFF;
            *(_DWORD *)(v3 + 60) = v12;
            *(_BYTE *)(v3 + 64) = *((_BYTE *)a1 + 64);
            v13 = a1[17];
            if ( v13 == 1 )
              v14 = 1;
            else
              v14 = 0x7FFFFFFF;
            if ( !v13 )
              v14 = 0;
            *(_DWORD *)(v3 + 68) = v14;
            *(_DWORD *)(v3 + 72) = a1[18];
            *(_DWORD *)(v3 + 76) = a1[19];
            *(_QWORD *)(v3 + 80) = *((_QWORD *)a1 + 10);
            *(_QWORD *)(v3 + 88) = *((_QWORD *)a1 + 11);
            *(_QWORD *)(v3 + 96) = *((_QWORD *)a1 + 12);
            if ( v5 != 2 )
            {
              *(_BYTE *)(v3 + 104) = *((_BYTE *)a1 + 104);
              v15 = a1[27];
              if ( v15 >= 3 )
                v15 = 0x7FFFFFFF;
              *(_DWORD *)(v3 + 108) = v15;
              *(_BYTE *)(v3 + 112) = *((_BYTE *)a1 + 112);
              v16 = a1[29];
              if ( v16 == 1 )
                v17 = 1;
              else
                v17 = 0x7FFFFFFF;
              if ( v16 )
                v18 = v17;
              else
                v18 = 0;
              *(_DWORD *)(v3 + 116) = v18;
              *(_DWORD *)(v3 + 120) = a1[30];
              *(_DWORD *)(v3 + 124) = a1[31];
              *(_QWORD *)(v3 + 128) = *((_QWORD *)a1 + 16);
              *(_QWORD *)(v3 + 136) = *((_QWORD *)a1 + 17);
              *(_QWORD *)(v3 + 144) = *((_QWORD *)a1 + 18);
            }
          }
        }
        *(_BYTE *)(v3 + 152) = *((_BYTE *)a1 + 152);
        v19 = a1[39];
        if ( v19 == 1 )
          v20 = 1;
        else
          v20 = 0x7FFFFFFF;
        if ( v19 )
          v21 = v20;
        else
          v21 = 0;
        *(_DWORD *)(v3 + 156) = v21;
        *(_DWORD *)(v3 + 160) = a1[40];
        *(_DWORD *)(v3 + 164) = a1[41];
        *(_QWORD *)(v3 + 168) = *((_QWORD *)a1 + 21);
        *(_QWORD *)(v3 + 176) = *((_QWORD *)a1 + 22);
        *(_QWORD *)(v3 + 184) = *((_QWORD *)a1 + 23);
        *(_QWORD *)(v3 + 192) = *((_QWORD *)a1 + 24);
        *(_QWORD *)(v3 + 200) = *((_QWORD *)a1 + 25);
        *(_QWORD *)(v3 + 208) = *((_QWORD *)a1 + 26);
        *(_QWORD *)(v3 + 216) = *((_QWORD *)a1 + 27);
        *(_DWORD *)(v3 + 224) = a1[56];
        *(_DWORD *)(v3 + 228) = a1[57];
        *(_QWORD *)(v3 + 232) = *((_QWORD *)a1 + 29);
        *(_DWORD *)(v3 + 240) = a1[60];
        *(_DWORD *)(v3 + 244) = a1[61];
        *(_BYTE *)(v3 + 248) = *((_BYTE *)a1 + 248);
        *(_QWORD *)(v3 + 256) = *((_QWORD *)a1 + 32);
        *(_BYTE *)(v3 + 264) = *((_BYTE *)a1 + 264);
        *(_DWORD *)(v3 + 268) = a1[67];
        *(_BYTE *)(v3 + 272) = *((_BYTE *)a1 + 272);
        *(_QWORD *)(v3 + 280) = *((_QWORD *)a1 + 35);
        *(_BYTE *)(v3 + 288) = *((_BYTE *)a1 + 288);
        *(_DWORD *)(v3 + 292) = a1[73];
        *(_BYTE *)(v3 + 296) = *((_BYTE *)a1 + 296);
        *(_QWORD *)(v3 + 304) = *((_QWORD *)a1 + 38);
        *(_BYTE *)(v3 + 312) = *((_BYTE *)a1 + 312);
        *(_DWORD *)(v3 + 316) = a1[79];
        *(_BYTE *)(v3 + 320) = *((_BYTE *)a1 + 320);
        *(_DWORD *)(v3 + 324) = a1[81];
        *(_BYTE *)(v3 + 328) = *((_BYTE *)a1 + 328);
        *(_DWORD *)(v3 + 332) = a1[83];
        v22 = os_if_qmi_txn_init();
        if ( v22 )
        {
          v7 = v22;
          v31 = "%s: QMI txn init failed for WFDS config message %d";
        }
        else
        {
          v32 = os_if_qmi_send_request((__int64)&qmi_wfds, 0, (__int64)&v42, 1, 0x141u);
          if ( v32 )
          {
            v7 = v32;
            qdf_trace_msg(
              0x48u,
              4u,
              "%s: QMI WFDS config send request failed %d",
              v33,
              v34,
              v35,
              v36,
              v37,
              v38,
              v39,
              v40,
              "os_if_qmi_wfds_send_config_msg",
              v32,
              v42,
              v43,
              v44,
              v45,
              v46,
              v47,
              v48,
              v49,
              v50,
              v51);
            os_if_qmi_txn_cancel();
            goto LABEL_45;
          }
          v7 = os_if_qmi_txn_wait();
          if ( !v7 )
            goto LABEL_45;
          v31 = "%s: Wait for QMI WFDS config response timed out %d";
        }
        qdf_trace_msg(
          0x48u,
          4u,
          v31,
          v23,
          v24,
          v25,
          v26,
          v27,
          v28,
          v29,
          v30,
          "os_if_qmi_wfds_send_config_msg",
          v7,
          v42,
          v43,
          v44,
          v45,
          v46,
          v47,
          v48,
          v49,
          v50,
          v51);
      }
      else
      {
        v7 = 4;
      }
LABEL_45:
      _qdf_mem_free(v6);
      _qdf_mem_free(v3);
      goto LABEL_46;
    }
    _qdf_mem_free(v3);
    v7 = 2;
  }
  else
  {
    v7 = 2;
  }
LABEL_46:
  _ReadStatusReg(SP_EL0);
  return v7;
}
