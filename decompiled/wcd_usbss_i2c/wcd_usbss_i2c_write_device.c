__int64 __fastcall wcd_usbss_i2c_write_device(__int64 a1, char a2, char *a3, int a4)
{
  __int64 v4; // x24
  __int64 v8; // x23
  _BYTE *v9; // x19
  unsigned __int16 v10; // w8
  char v11; // w8
  unsigned int v12; // w0
  unsigned int v13; // w20
  __int64 result; // x0
  unsigned __int64 StatusReg; // x25
  __int64 v16; // x26
  __int64 v17; // [xsp+8h] [xbp-28h] BYREF
  _BYTE *v18; // [xsp+10h] [xbp-20h]
  __int64 v19; // [xsp+18h] [xbp-18h]
  __int64 v20; // [xsp+20h] [xbp-10h]
  __int64 v21; // [xsp+28h] [xbp-8h]

  v21 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 16);
  if ( v4 )
  {
    v19 = 0;
    v20 = 0;
    v17 = 0;
    v18 = nullptr;
    v8 = (unsigned int)(a4 + 1);
    v9 = (_BYTE *)_kmalloc_noprof(v8, 3520);
    if ( v9 )
    {
      while ( 1 )
      {
        v10 = *(_WORD *)(v4 + 2);
        WORD2(v17) = a4 + 1;
        LODWORD(v17) = v10;
        if ( v8 )
        {
          *v9 = a2;
          if ( v8 != 1 )
            break;
        }
        __break(1u);
        v8 = (unsigned int)(a4 + 1);
        StatusReg = _ReadStatusReg(SP_EL0);
        v16 = *(_QWORD *)(StatusReg + 80);
        *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
        v9 = (_BYTE *)_kmalloc_noprof(v8, 3520);
        *(_QWORD *)(StatusReg + 80) = v16;
        if ( !v9 )
          goto LABEL_12;
      }
      v11 = *a3;
      v18 = v9;
      v9[1] = v11;
      if ( (unsigned int)i2c_transfer(*(_QWORD *)(v4 + 24), &v17, 1) == 1
        || (v12 = i2c_transfer(*(_QWORD *)(v4 + 24), &v17, 1), v12 == 1) )
      {
        v13 = 0;
      }
      else
      {
        v13 = v12;
        printk(&unk_B73C);
      }
      kfree(v9);
      result = v13;
    }
    else
    {
LABEL_12:
      result = 4294967284LL;
    }
  }
  else
  {
    result = 4294967277LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
