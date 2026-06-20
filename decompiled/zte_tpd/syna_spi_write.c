__int64 __fastcall syna_spi_write(__int64 **a1, const void *a2, __int64 a3)
{
  __int64 *v3; // x23
  __int64 v4; // x20
  unsigned int v5; // w19
  __int64 v7; // x0
  unsigned int v8; // w0
  __int64 v9; // x2
  __int64 v10; // x9
  __int64 v11; // x10
  _QWORD *v12; // x11
  int v13; // w12
  __int64 *v14; // x13
  __int64 v15; // x8
  __int64 *v16; // x0
  __int64 *v17; // x1
  __int64 **v18; // x8
  __int64 v19; // x8
  __int64 **v20; // x0
  __int64 **v21; // x1
  unsigned int v22; // w0
  void *v24; // x0
  __int64 v25; // [xsp+8h] [xbp-78h] BYREF
  __int64 *v26; // [xsp+10h] [xbp-70h]
  __int64 v27; // [xsp+18h] [xbp-68h]
  __int64 v28; // [xsp+20h] [xbp-60h]
  __int64 v29; // [xsp+28h] [xbp-58h]
  __int64 v30; // [xsp+30h] [xbp-50h]
  __int64 v31; // [xsp+38h] [xbp-48h]
  __int64 v32; // [xsp+40h] [xbp-40h]
  __int64 v33; // [xsp+48h] [xbp-38h]
  __int64 v34; // [xsp+50h] [xbp-30h]
  __int64 v35; // [xsp+58h] [xbp-28h]
  __int64 v36; // [xsp+60h] [xbp-20h] BYREF
  __int64 *v37; // [xsp+68h] [xbp-18h]
  __int64 v38; // [xsp+70h] [xbp-10h]
  __int64 v39; // [xsp+78h] [xbp-8h]

  v39 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a1;
  v37 = nullptr;
  v38 = 0;
  v35 = 0;
  v36 = 0;
  v33 = 0;
  v34 = 0;
  v31 = 0;
  v32 = 0;
  v29 = 0;
  v30 = 0;
  v27 = 0;
  v28 = 0;
  v25 = 0;
  v26 = nullptr;
  if ( !v3 )
  {
    v24 = &unk_3A459;
LABEL_30:
    printk(v24, "syna_spi_write", a3);
    v5 = -6;
    goto LABEL_27;
  }
  v4 = *v3;
  if ( !*v3 )
  {
    v24 = &unk_39DDD;
    goto LABEL_30;
  }
  v5 = a3;
  mutex_lock(v3 + 14);
  if ( (_WORD)v5 == 0xFFFF )
  {
    printk(&unk_370F6, "syna_spi_write", 0xFFFF);
    v5 = -22;
  }
  else
  {
    v38 = 0;
    v35 = 0;
    v33 = 0;
    v34 = 0;
    v31 = 0;
    v32 = 0;
    v29 = 0;
    v30 = 0;
    v27 = 0;
    v28 = 0;
    v25 = (__int64)&v25;
    v26 = &v25;
    v36 = (__int64)&v36;
    v37 = &v36;
    if ( *((_DWORD *)v3 + 25) )
      v7 = v5;
    else
      v7 = 1;
    v8 = syna_spi_alloc_mem(v7, v5);
    if ( (v8 & 0x80000000) != 0 )
    {
      v5 = v8;
      printk(&unk_35B63, "syna_spi_write", v9);
    }
    else if ( a2 && tx_buf )
    {
      memcpy((void *)tx_buf, a2, v5);
      if ( *((_DWORD *)v3 + 25) )
      {
        if ( v5 )
        {
          v10 = 0;
          v11 = 112;
          v12 = &unk_31000;
          v13 = 1;
          v14 = &v25;
          do
          {
            v15 = v12[232];
            v16 = (__int64 *)(v15 + v11);
            *((_DWORD *)v16 - 24) = v13;
            *(v16 - 14) = tx_buf + v10;
            v17 = v26;
            if ( (__int64 *)(v15 + v11) == v14 || v16 == v26 || (__int64 *)*v26 != v14 )
            {
              _list_add_valid_or_report(v16, v26);
            }
            else
            {
              v18 = (__int64 **)(v15 + v11);
              v26 = v16;
              *v18 = v14;
              v18[1] = v17;
              *v17 = (__int64)v16;
            }
            ++v10;
            v11 += 136;
          }
          while ( v5 != v10 );
        }
      }
      else
      {
        v19 = xfer;
        *(_QWORD *)xfer = tx_buf;
        v20 = (__int64 **)(v19 + 112);
        v21 = (__int64 **)v26;
        *(_DWORD *)(v19 + 16) = v5;
        if ( (__int64 *)(v19 + 112) == &v25 || v21 == v20 || *v21 != &v25 )
        {
          _list_add_valid_or_report(v20, v21);
        }
        else
        {
          v26 = (__int64 *)(v19 + 112);
          *(_QWORD *)(v19 + 112) = &v25;
          *(_QWORD *)(v19 + 120) = v21;
          *v21 = (__int64 *)v20;
        }
      }
      v22 = spi_sync(v4, &v25);
      if ( v22 )
      {
        v5 = v22;
        printk(&unk_394FC, "syna_spi_write", v22);
      }
    }
    else
    {
      printk(&unk_38E4F, "syna_spi_write", v9);
      v5 = -22;
    }
  }
  mutex_unlock(v3 + 14);
LABEL_27:
  _ReadStatusReg(SP_EL0);
  return v5;
}
