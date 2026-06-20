__int64 __fastcall gh_rm_vm_config_image(
        __int16 a1,
        __int16 a2,
        int a3,
        __int64 a4,
        __int64 a5,
        __int64 a6,
        __int64 a7)
{
  unsigned int v7; // w0
  __int64 result; // x0
  unsigned int v9; // w19
  __int64 v10; // [xsp+0h] [xbp-40h] BYREF
  __int64 v11; // [xsp+8h] [xbp-38h] BYREF
  _WORD v12[2]; // [xsp+10h] [xbp-30h] BYREF
  int v13; // [xsp+14h] [xbp-2Ch]
  __int64 v14; // [xsp+18h] [xbp-28h]
  __int64 v15; // [xsp+20h] [xbp-20h]
  __int64 v16; // [xsp+28h] [xbp-18h]
  __int64 v17; // [xsp+30h] [xbp-10h]
  __int64 v18; // [xsp+38h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12[0] = a1;
  v15 = a5;
  v12[1] = a2;
  v17 = a7;
  v16 = a6;
  v13 = a3;
  v14 = a4;
  v10 = 0;
  v11 = 0;
  v7 = gunyah_rm_call(rm, 1442840585, v12, 40, &v10, &v11);
  if ( v7 )
  {
    v9 = v7;
    printk(&unk_13854, "gh_rm_vm_config_image");
    result = v9;
  }
  else if ( v11 )
  {
    printk(&unk_13770, "gh_rm_vm_config_image");
    kfree(v10);
    result = 4294967274LL;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
