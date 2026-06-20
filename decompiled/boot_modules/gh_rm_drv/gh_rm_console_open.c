__int64 __fastcall gh_rm_console_open(unsigned __int16 a1)
{
  unsigned int v1; // w0
  __int64 result; // x0
  unsigned int v3; // w19
  __int64 v4; // [xsp+0h] [xbp-20h] BYREF
  int v5; // [xsp+Ch] [xbp-14h] BYREF
  _QWORD v6[2]; // [xsp+10h] [xbp-10h] BYREF

  v6[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v5 = a1;
  v6[0] = 0;
  v4 = 0;
  v1 = gunyah_rm_call(rm, 1442840705, &v5, 4, v6, &v4);
  if ( v1 )
  {
    v3 = v1;
    printk(&unk_13217, "gh_rm_console_open");
    result = v3;
  }
  else if ( v4 )
  {
    printk(&unk_12DE8, "gh_rm_console_open");
    kfree(v6[0]);
    result = 4294967274LL;
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
