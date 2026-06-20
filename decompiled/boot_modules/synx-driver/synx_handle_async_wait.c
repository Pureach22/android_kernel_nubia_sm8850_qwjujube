__int64 __fastcall synx_handle_async_wait(__int64 a1, __int64 a2)
{
  int v2; // w8
  __int64 v4; // x1
  __int64 result; // x0
  __int64 v6; // x5
  unsigned int v7; // w19
  __int64 v8; // [xsp+8h] [xbp-58h] BYREF
  __int64 (__fastcall *v9)(); // [xsp+10h] [xbp-50h]
  __int64 v10; // [xsp+18h] [xbp-48h]
  __int64 v11; // [xsp+20h] [xbp-40h]
  __int64 v12; // [xsp+28h] [xbp-38h]
  __int64 v13; // [xsp+30h] [xbp-30h] BYREF
  __int64 v14; // [xsp+38h] [xbp-28h]
  __int64 v15; // [xsp+40h] [xbp-20h]
  __int64 v16; // [xsp+48h] [xbp-18h]
  __int64 v17; // [xsp+50h] [xbp-10h]
  __int64 v18; // [xsp+58h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 4);
  v10 = 0;
  v11 = 0;
  v8 = 0;
  v9 = nullptr;
  if ( v2 == 40 )
  {
    v4 = *(_QWORD *)(a1 + 16);
    v16 = 0;
    v17 = 0;
    v14 = 0;
    v15 = 0;
    v13 = 0;
    if ( inline_copy_from_user((int)&v13, v4, 0x28u) )
    {
      result = 4294967282LL;
    }
    else
    {
      LODWORD(v8) = v13;
      v12 = v16;
      v9 = synx_util_default_user_callback;
      v10 = v14;
      result = synx_async_wait(a2, &v8);
      if ( (_DWORD)result && (synx_debug & 1) != 0 )
      {
        v7 = result;
        printk(&unk_2854E, &unk_29207, "synx_handle_async_wait", 3309, (unsigned int)v13, v6);
        result = v7;
      }
    }
  }
  else
  {
    result = 4294967274LL;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
