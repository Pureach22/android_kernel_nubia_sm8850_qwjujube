__int64 __fastcall gh_rm_vm_get_hyp_res(__int16 a1, _DWORD *a2)
{
  int v3; // w0
  __int64 v4; // x1
  __int64 v5; // x20
  __int64 v6; // x0
  unsigned __int64 v8; // [xsp+0h] [xbp-20h] BYREF
  _WORD v9[2]; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v10[2]; // [xsp+10h] [xbp-10h] BYREF

  v10[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = a1;
  v9[1] = 0;
  if ( a2 )
  {
    v10[0] = 0;
    v8 = 0;
    v3 = gunyah_rm_call(rm, 1442840608, v9, 4, v10, &v8);
    if ( v3 )
    {
      LODWORD(v5) = v3;
      printk(&unk_12358, "gh_rm_vm_get_hyp_res");
      v5 = (int)v5;
    }
    else
    {
      if ( v8 >= 4 && *(_DWORD *)v10[0] < 0x5D1745Du && (v4 = 44LL * *(unsigned int *)v10[0], v8 == v4 + 4) )
      {
        v5 = kmemdup_noprof(v10[0] + 4LL, v4, 3264);
        v6 = v10[0];
        if ( v5 )
          *a2 = *(_DWORD *)v10[0];
        else
          v5 = -12;
      }
      else
      {
        printk(&unk_136F6, "gh_rm_vm_get_hyp_res");
        v6 = v10[0];
        v5 = -22;
      }
      kfree(v6);
    }
  }
  else
  {
    v5 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return v5;
}
