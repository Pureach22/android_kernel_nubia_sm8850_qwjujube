__int64 __fastcall dsi_hfi_append_panel_generic_caps(__int64 a1, __int64 a2, int *a3)
{
  __int64 v3; // x21
  int v5; // w22
  int v7; // w10
  int v8; // w10
  int v9; // w10
  int v10; // w12
  int v11; // w12
  int v12; // w12
  int v13; // w12
  int v14; // w13
  int v15; // w13
  int v16; // w12
  int v17; // w11
  int v18; // w10
  int v19; // w10
  int v20; // w11
  int v21; // w10
  unsigned int *v22; // x0
  unsigned int v23; // w8
  unsigned __int64 v24; // x24
  int v25; // w22
  __int64 v26; // x25
  unsigned int v27; // w19
  __int64 v28; // x20
  int v29; // t1
  unsigned int count; // w20
  __int64 payload_addr; // x0
  _DWORD v33[2]; // [xsp+0h] [xbp-D0h] BYREF
  int v34; // [xsp+8h] [xbp-C8h] BYREF
  int v35; // [xsp+Ch] [xbp-C4h]
  int v36; // [xsp+10h] [xbp-C0h] BYREF
  int v37; // [xsp+14h] [xbp-BCh]
  int v38; // [xsp+18h] [xbp-B8h] BYREF
  int v39; // [xsp+1Ch] [xbp-B4h]
  int v40; // [xsp+20h] [xbp-B0h] BYREF
  int v41; // [xsp+24h] [xbp-ACh]
  int v42; // [xsp+28h] [xbp-A8h] BYREF
  int v43; // [xsp+2Ch] [xbp-A4h]
  int v44; // [xsp+30h] [xbp-A0h] BYREF
  int v45; // [xsp+34h] [xbp-9Ch]
  int v46; // [xsp+38h] [xbp-98h] BYREF
  int v47; // [xsp+3Ch] [xbp-94h]
  int v48; // [xsp+40h] [xbp-90h] BYREF
  int v49; // [xsp+44h] [xbp-8Ch]
  int v50; // [xsp+48h] [xbp-88h] BYREF
  int v51; // [xsp+4Ch] [xbp-84h]
  int v52; // [xsp+50h] [xbp-80h] BYREF
  int v53; // [xsp+54h] [xbp-7Ch]
  int v54; // [xsp+58h] [xbp-78h] BYREF
  int v55; // [xsp+5Ch] [xbp-74h]
  int v56; // [xsp+60h] [xbp-70h] BYREF
  int v57; // [xsp+64h] [xbp-6Ch]
  int v58; // [xsp+68h] [xbp-68h] BYREF
  int v59; // [xsp+6Ch] [xbp-64h]
  int v60; // [xsp+70h] [xbp-60h] BYREF
  int v61; // [xsp+74h] [xbp-5Ch]
  int v62; // [xsp+78h] [xbp-58h] BYREF
  _DWORD v63[19]; // [xsp+7Ch] [xbp-54h]
  __int64 v64; // [xsp+C8h] [xbp-8h]

  v64 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 1688);
  if ( v3 )
  {
    v5 = *a3;
    hfi_util_kv_helper_reset(*(unsigned int **)(v3 + 16));
    v7 = a3[2];
    v62 = a3[1];
    v63[0] = 262154;
    v33[0] = v7;
    v33[1] = 262155;
    v8 = a3[8];
    v36 = a3[7];
    v37 = 262160;
    v38 = v8;
    v39 = 262185;
    v9 = a3[10];
    v40 = a3[9];
    v41 = 262186;
    v10 = a3[14];
    v42 = a3[13];
    v43 = 262164;
    v44 = v10;
    v45 = 262165;
    v11 = a3[16];
    v46 = a3[15];
    v47 = 262166;
    v48 = v11;
    v49 = 262167;
    v12 = a3[18];
    v50 = a3[17];
    v51 = 262168;
    v52 = v12;
    v53 = 262169;
    v13 = a3[20];
    v54 = a3[19];
    v55 = 262170;
    v14 = a3[25];
    v56 = v13;
    v57 = 262171;
    v58 = v14;
    v59 = 262184;
    v15 = a3[22];
    v60 = a3[21];
    v61 = 262172;
    v16 = a3[4];
    v63[1] = a3[3];
    v63[2] = 262156;
    v17 = a3[5];
    v63[3] = v16;
    v63[4] = 262157;
    v63[5] = v17;
    v63[6] = 262158;
    v63[7] = v9;
    v63[8] = 262161;
    v18 = a3[12];
    v63[9] = a3[11];
    v63[10] = 262162;
    v63[11] = v18;
    v63[12] = 262163;
    v19 = a3[23];
    v20 = a3[24];
    v63[13] = v15;
    v63[14] = 262176;
    v63[15] = v19;
    v63[16] = 262177;
    v21 = a3[6];
    v63[17] = v20;
    v63[18] = 262178;
    v22 = *(unsigned int **)(v3 + 16);
    v34 = v21;
    v35 = 262159;
    hfi_util_kv_helper_add(v22, 0x104000Bu, (__int64)v33);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v35 | 0x1000000, (__int64)&v34);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v37 | 0x1000000, (__int64)&v36);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v39 | 0x1000000, (__int64)&v38);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v41 | 0x1000000, (__int64)&v40);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v43 | 0x1000000, (__int64)&v42);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v45 | 0x1000000, (__int64)&v44);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v47 | 0x1000000, (__int64)&v46);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v49 | 0x1000000, (__int64)&v48);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v51 | 0x1000000, (__int64)&v50);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v53 | 0x1000000, (__int64)&v52);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v55 | 0x1000000, (__int64)&v54);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v57 | 0x1000000, (__int64)&v56);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v59 | 0x1000000, (__int64)&v58);
    hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v61 | 0x1000000, (__int64)&v60);
    v23 = v5 - 2;
    if ( v5 - 2 >= 16 )
    {
      v24 = 0;
      v25 = 60;
      v26 = 8LL * v23 - 120;
      while ( 1 )
      {
        if ( v24 == 80 )
          goto LABEL_19;
        if ( v63[v24 / 4 - 1] )
        {
          if ( v24 + 124 > 0xC8 )
          {
            __break(1u);
LABEL_19:
            __break(0x5512u);
          }
          hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), v63[v24 / 4] | 0x1000000, (__int64)&v63[v24 / 4 - 1]);
          v25 += 4;
        }
        v24 += 8LL;
        if ( v26 == v24 )
          goto LABEL_11;
      }
    }
    v25 = 60;
LABEL_11:
    if ( a3[26] )
    {
      hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x304001Du, (__int64)(a3 + 26));
      v25 += 12;
    }
    v29 = a3[29];
    v28 = (__int64)(a3 + 29);
    if ( v29 )
    {
      hfi_util_kv_helper_add(*(unsigned int **)(v3 + 16), 0x304001Eu, v28);
      v25 += 12;
    }
    count = hfi_util_kv_helper_get_count(*(_QWORD *)(v3 + 16));
    payload_addr = hfi_util_kv_helper_get_payload_addr(*(_QWORD *)(v3 + 16));
    v27 = hfi_adapter_add_prop_array(a1, 0x3000003u, 0, 2u, payload_addr, count, v25 + 4 * count);
    if ( v27 )
      drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Failed to add caps to buffer, rc = %d", v27);
  }
  else
  {
    v27 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v27;
}
