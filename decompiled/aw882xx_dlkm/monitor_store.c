__int64 __fastcall monitor_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 v4; // x9
  __int64 v5; // x20
  __int64 result; // x0
  __int64 *v8; // x8
  __int64 v9; // x1
  int v10; // w8
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(_QWORD *)(a1 + 152);
  v11 = 0;
  v5 = *(_QWORD *)(v4 + 96);
  if ( a4 )
  {
    LODWORD(result) = kstrtouint(a3, 0, &v11);
    if ( (result & 0x80000000) != 0 )
    {
      result = (int)result;
    }
    else
    {
      v8 = *(__int64 **)(v5 + 112);
      v9 = v8[14];
      if ( !v9 )
        v9 = *v8;
      printk(&unk_25360, v9, "monitor_store");
      v10 = v11;
      if ( *(_DWORD *)(v5 + 780) != v11 )
      {
        *(_DWORD *)(v5 + 780) = v11;
        if ( v10 )
          aw882xx_monitor_start(v5 + 672);
      }
      result = a4;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
