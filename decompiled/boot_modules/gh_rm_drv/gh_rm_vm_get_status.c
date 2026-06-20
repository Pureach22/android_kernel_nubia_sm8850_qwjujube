__int64 __fastcall gh_rm_vm_get_status(__int16 a1)
{
  int v1; // w0
  __int64 v2; // x0
  __int64 v3; // x19
  __int64 v5; // [xsp+0h] [xbp-20h] BYREF
  __int64 v6; // [xsp+8h] [xbp-18h] BYREF
  _WORD v7[2]; // [xsp+14h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+18h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7[0] = a1;
  v7[1] = 0;
  v5 = 0;
  v6 = 0;
  v1 = gunyah_rm_call(rm, 1442840599, v7, 4, &v6, &v5);
  if ( v1 )
  {
    LODWORD(v3) = v1;
    printk(&unk_12D6B, "gh_rm_vm_get_status");
    v3 = (int)v3;
    if ( !v6 )
      goto LABEL_8;
  }
  else if ( v5 == 4 )
  {
    v2 = kmemdup_noprof(v6, 4, 3264);
    if ( v2 )
      v3 = v2;
    else
      v3 = -12;
  }
  else
  {
    printk(&unk_11FF8, "gh_rm_vm_get_status");
    v3 = -22;
  }
  if ( v5 )
    kfree(v6);
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return v3;
}
