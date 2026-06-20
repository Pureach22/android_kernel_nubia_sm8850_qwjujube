size_t __fastcall enable_store(__int64 a1, int a2, unsigned __int64 a3)
{
  __int64 v4; // x20
  size_t v5; // x19
  __int64 v6; // x6
  __int64 v8; // x2
  __int64 v9; // x3
  __int64 v10; // x4
  __int64 v11; // x5
  __int64 v12; // x6
  unsigned int v13; // w1
  unsigned int v14; // [xsp+4h] [xbp-1Ch] BYREF
  __int64 v15; // [xsp+8h] [xbp-18h] BYREF
  __int16 v16; // [xsp+10h] [xbp-10h]
  __int64 v17; // [xsp+18h] [xbp-8h]

  v17 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = g_aw86320;
  v14 = 0;
  if ( a3 >= 9 )
    v5 = 9;
  else
    v5 = a3;
  v16 = 0;
  v15 = 0;
  _check_object_size(&v15, v5, 0);
  if ( (unsigned int)inline_copy_from_user((int)&v15, a2, v5) || (unsigned int)kstrtouint(&v15, 0, &v14) )
  {
    v5 = -22;
  }
  else
  {
    printk(&unk_9C32, "aw86320", 779, "enable_store", "enable_store", v14, v6);
    v13 = v14;
    if ( v14 >= 2 )
    {
      v13 = 1;
      v14 = 1;
    }
    enableMicroPump(v4, v13, v8, v9, v10, v11, v12);
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
