__int64 __fastcall gh_rm_vm_get_id(__int16 a1, _DWORD *a2)
{
  int v3; // w0
  __int64 result; // x0
  int v5; // w8
  __int64 v6; // x3
  __int64 v7; // x9
  __int64 v8; // x10
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x20
  int v12; // w20
  unsigned __int64 v13; // [xsp+0h] [xbp-20h] BYREF
  _WORD v14[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v15[2]; // [xsp+10h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v14[0] = a1;
  v14[1] = 0;
  if ( a2 )
  {
    v15[0] = 0;
    v13 = 0;
    v3 = gunyah_rm_call(rm, 1442840592, v14, 4, v15, &v13);
    if ( v3 )
    {
      v12 = v3;
      printk(&unk_13809, "gh_rm_vm_get_id");
      result = v12;
    }
    else if ( v13 > 3 )
    {
      v5 = *(_DWORD *)v15[0];
      if ( *(_DWORD *)v15[0] )
      {
        v6 = 0;
        v7 = v15[0] + 4LL;
        do
        {
          --v5;
          v8 = (*(unsigned __int16 *)(v7 + 2) - 1LL) | 3;
          v6 += v8 + 5;
          v7 += v8 + 5;
        }
        while ( v5 );
      }
      else
      {
        v6 = 0;
      }
      if ( v6 == v13 - 4 )
      {
        v9 = kmemdup_noprof(v15[0] + 4LL, v6, 3264);
        v10 = v15[0];
        if ( v9 )
        {
          v11 = v9;
          *a2 = *(_DWORD *)v15[0];
        }
        else
        {
          v11 = -12;
        }
      }
      else
      {
        printk(&unk_13624, "gh_rm_vm_get_id");
        v10 = v15[0];
        v11 = -22;
      }
      kfree(v10);
      result = v11;
    }
    else
    {
      if ( v13 )
        kfree(v15[0]);
      result = -74;
    }
  }
  else
  {
    result = -22;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
