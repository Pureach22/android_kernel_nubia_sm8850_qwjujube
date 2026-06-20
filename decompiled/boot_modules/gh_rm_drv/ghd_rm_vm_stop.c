__int64 __fastcall ghd_rm_vm_stop(__int16 a1, unsigned int a2, char a3)
{
  unsigned int v3; // w0
  __int64 result; // x0
  unsigned int v5; // w19
  __int64 v6; // [xsp+0h] [xbp-20h] BYREF
  __int64 v7; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v8[2]; // [xsp+10h] [xbp-10h] BYREF

  v8[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  v8[0] = 0;
  v6 = 0;
  if ( a2 >= 4 )
  {
    printk(&unk_134CA, "ghd_rm_vm_stop");
LABEL_9:
    result = 4294967274LL;
    goto LABEL_5;
  }
  LOWORD(v8[0]) = a1;
  HIDWORD(v8[0]) = a2;
  BYTE2(v8[0]) = a3;
  v3 = gunyah_rm_call(rm, 1442840581, v8, 8, &v6, &v7);
  if ( v3 )
  {
    v5 = v3;
    printk(&unk_1205F, "ghd_rm_vm_stop");
    result = v5;
    goto LABEL_5;
  }
  if ( v7 )
  {
    printk(&unk_12D92, "ghd_rm_vm_stop");
    kfree(v6);
    goto LABEL_9;
  }
  result = 0;
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return result;
}
