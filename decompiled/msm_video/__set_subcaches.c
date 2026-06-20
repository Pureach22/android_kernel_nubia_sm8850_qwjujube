__int64 __fastcall _set_subcaches(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v6; // x8
  __int64 result; // x0
  int v8; // w3
  __int64 v9; // x0
  unsigned int v10; // w1
  __int64 v11; // x8
  unsigned int v12; // w9
  unsigned __int64 v13; // x24
  int v14; // w8
  int v15; // w5
  int v16; // w8
  int v17; // w6
  unsigned int *v18; // x0
  unsigned int v19; // w1
  __int64 v20; // x20
  __int64 v21; // x8
  _DWORD *v22; // x8
  unsigned int v23; // w20
  __int64 v24; // x8
  unsigned __int64 v25; // x24
  __int64 v26; // [xsp+8h] [xbp-48h] BYREF
  __int64 v27; // [xsp+10h] [xbp-40h]
  __int64 v28; // [xsp+18h] [xbp-38h]
  __int64 v29; // [xsp+20h] [xbp-30h]
  __int64 v30; // [xsp+28h] [xbp-28h]
  __int64 v31; // [xsp+30h] [xbp-20h]
  __int64 v32; // [xsp+38h] [xbp-18h]
  __int64 v33; // [xsp+40h] [xbp-10h]
  __int64 v34; // [xsp+48h] [xbp-8h]

  v34 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (msm_vidc_syscache_disable & 1) != 0 || !*(_DWORD *)(*(_QWORD *)(a1 + 3912) + 120LL) )
  {
LABEL_5:
    result = 0;
    goto LABEL_6;
  }
  v6 = *(_QWORD *)(a1 + 3904);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  LODWORD(v6) = *(unsigned __int8 *)(v6 + 108);
  v28 = 0;
  v29 = 0;
  v26 = 0;
  v27 = 0;
  if ( (_DWORD)v6 == 1 )
  {
    if ( (msm_vidc_debug & 2) != 0 )
    {
      printk(&unk_8F698, "high", 0xFFFFFFFFLL, "codec", a5);
      result = 0;
      goto LABEL_6;
    }
    goto LABEL_5;
  }
  v8 = *(_DWORD *)(a1 + 6600);
  v9 = *(_QWORD *)(a1 + 6464);
  v10 = *(_DWORD *)(a1 + 6472);
  *(_DWORD *)(a1 + 6600) = v8 + 1;
  result = hfi_create_header(v9, v10, 0, v8);
  if ( (_DWORD)result )
    goto LABEL_28;
  v11 = *(_QWORD *)(a1 + 3904);
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v12 = *(_DWORD *)(v11 + 104);
  v13 = *(_QWORD *)(v11 + 96);
  v28 = 0;
  v29 = 0;
  v27 = 0;
  v26 = 4;
  if ( v13 < v13 + 24LL * v12 )
  {
    do
    {
      if ( *(_BYTE *)(v13 + 20) != 1 )
        goto LABEL_10;
      v14 = **(_DWORD **)v13;
      HIDWORD(v28) = *(_QWORD *)(*(_QWORD *)v13 + 8LL);
      v15 = *(_DWORD *)(v13 + 16);
      HIDWORD(v26) = v14;
      if ( v15 > 69 )
      {
        if ( v15 == 70 )
        {
          v16 = 4;
        }
        else
        {
          if ( v15 != 83 )
          {
LABEL_19:
            if ( (msm_vidc_debug & 1) != 0 )
              printk(&unk_82E2B, "err ", 0xFFFFFFFFLL, "codec", "__get_hfi_subcache_type");
            v16 = 0;
            goto LABEL_24;
          }
          v16 = 5;
        }
      }
      else if ( v15 == 2 )
      {
        v16 = 1;
      }
      else
      {
        if ( v15 != 64 )
          goto LABEL_19;
        v16 = 2;
      }
LABEL_24:
      v17 = *(_DWORD *)(a1 + 6604);
      v18 = *(unsigned int **)(a1 + 6464);
      v19 = *(_DWORD *)(a1 + 6472);
      HIDWORD(v31) = v16;
      *(_DWORD *)(a1 + 6604) = v17 + 1;
      result = hfi_create_packet(v18, v19, 16777225, 0, 5, 0, v17, &v26, 0x40u);
      if ( (_DWORD)result )
        goto LABEL_28;
      v11 = *(_QWORD *)(a1 + 3904);
LABEL_10:
      v13 += 24LL;
    }
    while ( v13 < *(_QWORD *)(v11 + 96) + 24 * (unsigned __int64)*(unsigned int *)(v11 + 104) );
  }
  v20 = *(_QWORD *)(a1 + 6464);
  result = _resume(a1);
  if ( (_DWORD)result || (result = venus_hfi_queue_cmd_write(a1, v20), (_DWORD)result) )
  {
LABEL_28:
    if ( a1 )
    {
      v21 = *(_QWORD *)(a1 + 6552);
      if ( v21 )
      {
        v22 = *(_DWORD **)(v21 + 88);
        if ( v22 )
        {
          v23 = result;
          if ( *(v22 - 1) != -254569353 )
            __break(0x8228u);
          ((void (__fastcall *)(__int64, _QWORD))v22)(a1, 0);
          result = v23;
        }
      }
    }
  }
  else
  {
    _schedule_power_collapse_work(a1);
    v24 = *(_QWORD *)(a1 + 3904);
    v25 = *(_QWORD *)(v24 + 96);
    if ( v25 < v25 + 24LL * *(unsigned int *)(v24 + 104) )
    {
      do
      {
        if ( *(_BYTE *)(v25 + 20) == 1 && (msm_vidc_debug & 2) != 0 )
        {
          printk(&unk_90368, "high", 0xFFFFFFFFLL, "codec", "__set_subcaches");
          v24 = *(_QWORD *)(a1 + 3904);
        }
        v25 += 24LL;
      }
      while ( v25 < *(_QWORD *)(v24 + 96) + 24 * (unsigned __int64)*(unsigned int *)(v24 + 104) );
    }
    result = 0;
    *(_BYTE *)(v24 + 108) = 1;
  }
LABEL_6:
  _ReadStatusReg(SP_EL0);
  return result;
}
