__int64 __fastcall cam_spi_tx_helper(__int64 a1, _BYTE *a2, int a3, void *a4, int a5, unsigned int a6)
{
  __int64 *v6; // x8
  __int64 v7; // x24
  unsigned int v8; // w25
  unsigned int v9; // w19
  unsigned __int64 v15; // x21
  _BYTE *v16; // x22
  __int64 v17; // x25
  const char *v18; // x5
  __int64 v19; // x4
  __int64 result; // x0
  int v21; // w9
  int v22; // w0
  unsigned int v23; // w21
  unsigned __int64 StatusReg; // x20
  __int64 v25; // x25
  __int64 v26; // x0
  void *dest; // [xsp+8h] [xbp-118h]
  unsigned int v28; // [xsp+10h] [xbp-110h]
  unsigned int v29; // [xsp+10h] [xbp-110h]
  unsigned int v30; // [xsp+14h] [xbp-10Ch]
  _QWORD v31[11]; // [xsp+18h] [xbp-108h] BYREF
  _QWORD v32[5]; // [xsp+70h] [xbp-B0h] BYREF
  int v33; // [xsp+98h] [xbp-88h]
  int v34; // [xsp+9Ch] [xbp-84h]
  __int64 v35; // [xsp+A0h] [xbp-80h]
  __int64 v36; // [xsp+A8h] [xbp-78h]
  __int64 v37; // [xsp+B0h] [xbp-70h]
  __int64 v38; // [xsp+B8h] [xbp-68h]
  __int64 v39; // [xsp+C0h] [xbp-60h]
  __int64 v40; // [xsp+C8h] [xbp-58h]
  __int64 v41; // [xsp+D0h] [xbp-50h]
  __int64 v42; // [xsp+D8h] [xbp-48h]
  __int64 v43; // [xsp+E0h] [xbp-40h]
  __int64 v44; // [xsp+E8h] [xbp-38h]
  __int64 v45; // [xsp+F0h] [xbp-30h]
  _QWORD v46[5]; // [xsp+F8h] [xbp-28h] BYREF

  v46[3] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6 = *(__int64 **)(a1 + 24);
  v7 = *v6;
  if ( !*v6 )
  {
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_tx_helper",
      122,
      "Invalid arguments");
    result = 4294967274LL;
    goto LABEL_39;
  }
  v8 = a6;
  LOBYTE(v9) = *((_BYTE *)v6 + 48);
  v15 = (unsigned __int8)a2[1] + (unsigned __int8)a2[2] + 1 + a6;
  v30 = (unsigned __int8)a2[1] + (unsigned __int8)a2[2] + 1;
  v16 = (_BYTE *)_kmalloc_noprof(v15, 3521);
  if ( !v16 )
  {
LABEL_37:
    v18 = "Fail to allocate Memory: len: %u";
    v19 = 133;
LABEL_38:
    ((void (__fastcall *)(__int64, __int64, __int64, const char *, __int64, const char *, _QWORD))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_tx_helper",
      v19,
      v18,
      (unsigned int)v15);
    result = 4294967284LL;
    goto LABEL_39;
  }
  while ( 1 )
  {
    v28 = v8;
    if ( v8 )
    {
      v17 = _kmalloc_noprof(v15, 3521);
      if ( !v17 )
      {
        kfree(v16);
        v18 = "Fail to allocate memory: len: %u";
        v19 = 151;
        goto LABEL_38;
      }
    }
    else
    {
      v17 = 0;
    }
    if ( !v15 )
      goto LABEL_36;
    v21 = (unsigned __int8)a2[1];
    *v16 = *a2;
    if ( !v21 )
      goto LABEL_27;
    if ( a5 != 3 )
      break;
    if ( v15 != 1 )
    {
      v16[1] = BYTE2(a3);
      if ( v15 != 2 )
      {
        v16[2] = BYTE1(a3);
        if ( v15 >= 4 )
        {
          v16[3] = a3;
          goto LABEL_27;
        }
      }
    }
LABEL_36:
    __break(1u);
    dest = a4;
    StatusReg = _ReadStatusReg(SP_EL0);
    v29 = v17;
    v25 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &cam_spi_tx_helper__alloc_tag;
    v26 = _kmalloc_noprof(v15, 3521);
    *(_QWORD *)(StatusReg + 80) = v25;
    v8 = v29;
    a4 = dest;
    v16 = (_BYTE *)v26;
    if ( !v26 )
      goto LABEL_37;
  }
  if ( a5 == 2 )
  {
    if ( v15 != 1 )
    {
      v16[1] = BYTE1(a3);
      if ( v15 != 2 )
      {
        v16[2] = a3;
        goto LABEL_27;
      }
    }
    goto LABEL_36;
  }
  if ( a5 == 1 )
  {
    if ( v15 != 1 )
    {
      v16[1] = a3;
      goto LABEL_27;
    }
    goto LABEL_36;
  }
  if ( v15 == 1 )
    goto LABEL_36;
  v16[1] = HIBYTE(a3);
  if ( v15 == 2 )
    goto LABEL_36;
  v16[2] = BYTE2(a3);
  if ( v15 < 4 )
    goto LABEL_36;
  v16[3] = BYTE1(a3);
  if ( v15 == 4 )
    goto LABEL_36;
  v16[4] = a3;
LABEL_27:
  while ( 1 )
  {
    v46[2] = 0;
    v45 = 0;
    v43 = 0;
    v44 = 0;
    v41 = 0;
    v42 = 0;
    v39 = 0;
    v40 = 0;
    v37 = 0;
    v38 = 0;
    v35 = 0;
    v36 = 0;
    v34 = 0;
    v32[3] = v16;
    v32[4] = v17;
    v33 = v15;
    memset(&v31[2], 0, 72);
    v32[2] = 0;
    v32[0] = v32;
    v32[1] = v32;
    v31[1] = v46;
    v46[0] = v31;
    v46[1] = v31;
    v31[0] = v46;
    v22 = spi_sync(v7, v31);
    if ( !v22 )
      break;
    v9 = (unsigned __int8)v9 + 255;
    if ( !(v9 >> 8) )
      break;
    msleep(*(unsigned __int8 *)(*(_QWORD *)(a1 + 24) + 47LL));
  }
  v23 = v22;
  if ( v22 < 0 )
  {
    ((void (*)(__int64, __int64, __int64, const char *, __int64, const char *, ...))cam_print_log)(
      3,
      0x4000000000LL,
      1,
      "cam_spi_tx_helper",
      167,
      "failed: spi txfr rc %d",
      v22);
  }
  else if ( a4 && v28 )
  {
    memcpy(a4, (const void *)(v17 + v30), v28);
  }
  kfree(v16);
  kfree(v17);
  result = v23;
LABEL_39:
  _ReadStatusReg(SP_EL0);
  return result;
}
