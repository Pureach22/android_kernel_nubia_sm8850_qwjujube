__int64 __fastcall gh_rm_mem_release(int a1, unsigned __int8 a2)
{
  unsigned int v2; // w0
  __int64 result; // x0
  unsigned int v4; // w20
  __int64 v5; // [xsp+10h] [xbp-20h] BYREF
  __int64 v6; // [xsp+18h] [xbp-18h] BYREF
  _DWORD v7[2]; // [xsp+20h] [xbp-10h] BYREF
  __int64 v8; // [xsp+28h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( a2 > 1u )
  {
    result = 4294967274LL;
  }
  else
  {
    v5 = 0;
    v6 = 0;
    v7[0] = a1;
    v7[1] = a2;
    v2 = gunyah_rm_call(rm, 1358954516, v7, 8, &v6, &v5);
    if ( v2 )
    {
      v4 = v2;
      printk(&unk_13114, "gh_rm_mem_release_helper");
      result = v4;
    }
    else if ( v5 )
    {
      kfree(v6);
      result = 4294967222LL;
    }
    else
    {
      result = 0;
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
