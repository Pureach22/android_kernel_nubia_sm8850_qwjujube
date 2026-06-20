__int64 __fastcall syna_spi_read(__int64 **a1, void *a2, __int64 a3)
{
  __int64 *v3; // x22
  __int64 v4; // x21
  unsigned int v5; // w19
  __int64 v7; // x0
  unsigned int v8; // w0
  __int64 v9; // x2
  __int64 v10; // x9
  __int64 v11; // x10
  __int64 v12; // x11
  _QWORD *v13; // x12
  int v14; // w13
  __int64 *v15; // x14
  __int64 v16; // x8
  __int64 *v17; // x0
  __int64 *v18; // x1
  __int64 **v19; // x8
  __int64 v20; // x8
  __int64 *v21; // x0
  __int64 v22; // x9
  _QWORD *v23; // x1
  unsigned int v24; // w0
  __int64 v25; // x2
  void *v27; // x0
  __int64 v28; // [xsp+8h] [xbp-78h] BYREF
  __int64 *v29; // [xsp+10h] [xbp-70h]
  __int64 v30; // [xsp+18h] [xbp-68h]
  __int64 v31; // [xsp+20h] [xbp-60h]
  __int64 v32; // [xsp+28h] [xbp-58h]
  __int64 v33; // [xsp+30h] [xbp-50h]
  __int64 v34; // [xsp+38h] [xbp-48h]
  __int64 v35; // [xsp+40h] [xbp-40h]
  __int64 v36; // [xsp+48h] [xbp-38h]
  __int64 v37; // [xsp+50h] [xbp-30h]
  __int64 v38; // [xsp+58h] [xbp-28h]
  __int64 v39; // [xsp+60h] [xbp-20h] BYREF
  __int64 *v40; // [xsp+68h] [xbp-18h]
  __int64 v41; // [xsp+70h] [xbp-10h]
  __int64 v42; // [xsp+78h] [xbp-8h]

  v42 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v40 = nullptr;
  v41 = 0;
  v38 = 0;
  v39 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = 0;
  v29 = nullptr;
  if ( !v3 )
  {
    v27 = &unk_3A459;
LABEL_30:
    printk(v27, "syna_spi_read", a3);
    v5 = -6;
    goto LABEL_27;
  }
  v4 = *v3;
  if ( !*v3 )
  {
    v27 = &unk_39DDD;
    goto LABEL_30;
  }
  v5 = a3;
  mutex_lock(v3 + 14);
  if ( (_WORD)v5 == 0xFFFF )
  {
    printk(&unk_325AE, "syna_spi_read", 0xFFFF);
LABEL_35:
    v5 = -22;
    goto LABEL_26;
  }
  v41 = 0;
  v38 = 0;
  v36 = 0;
  v37 = 0;
  v34 = 0;
  v35 = 0;
  v32 = 0;
  v33 = 0;
  v30 = 0;
  v31 = 0;
  v28 = (__int64)&v28;
  v29 = &v28;
  v39 = (__int64)&v39;
  v40 = &v39;
  if ( *((_DWORD *)v3 + 25) )
    v7 = v5;
  else
    v7 = 1;
  v8 = syna_spi_alloc_mem(v7, v5);
  if ( (v8 & 0x80000000) != 0 )
  {
    v5 = v8;
    printk(&unk_3BFF0, "syna_spi_read", v9);
    goto LABEL_26;
  }
  if ( *((_DWORD *)v3 + 25) )
  {
    *(_BYTE *)tx_buf = -1;
    if ( v5 )
    {
      v10 = 0;
      v11 = v5;
      v12 = 112;
      v13 = &unk_31000;
      v14 = 1;
      v15 = &v28;
      do
      {
        v16 = v13[232];
        v17 = (__int64 *)(v16 + v12);
        *((_DWORD *)v17 - 24) = v14;
        *(v17 - 14) = tx_buf;
        *(v17 - 13) = rx_buf + v10;
        v18 = v29;
        if ( (__int64 *)(v16 + v12) == v15 || v17 == v29 || (__int64 *)*v29 != v15 )
        {
          _list_add_valid_or_report(v17, v29);
        }
        else
        {
          v19 = (__int64 **)(v16 + v12);
          v29 = v17;
          *v19 = v15;
          v19[1] = v18;
          *v18 = (__int64)v17;
        }
        ++v10;
        v12 += 136;
      }
      while ( v11 != v10 );
    }
  }
  else
  {
    memset((void *)tx_buf, 255, v5);
    v20 = xfer;
    *(_QWORD *)xfer = tx_buf;
    v21 = (__int64 *)(v20 + 112);
    v22 = rx_buf;
    *(_DWORD *)(v20 + 16) = v5;
    *(_QWORD *)(v20 + 8) = v22;
    v23 = v29;
    if ( (__int64 *)(v20 + 112) == &v28 || v29 == v21 || (__int64 *)*v29 != &v28 )
    {
      _list_add_valid_or_report(v21, v29);
    }
    else
    {
      v29 = (__int64 *)(v20 + 112);
      *(_QWORD *)(v20 + 112) = &v28;
      *(_QWORD *)(v20 + 120) = v23;
      *v23 = v21;
    }
  }
  v24 = spi_sync(v4, &v28);
  if ( v24 )
  {
    v5 = v24;
    printk(&unk_355EA, "syna_spi_read", v24);
    goto LABEL_26;
  }
  if ( !a2 || !rx_buf )
  {
    printk(&unk_3AB30, "syna_spi_read", v25);
    goto LABEL_35;
  }
  memcpy(a2, (const void *)rx_buf, v5);
LABEL_26:
  mutex_unlock(v3 + 14);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v5;
}
