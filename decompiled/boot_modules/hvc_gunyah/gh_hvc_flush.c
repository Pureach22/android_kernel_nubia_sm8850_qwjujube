__int64 __fastcall gh_hvc_flush(int a1, char a2)
{
  unsigned int v2; // w19
  __int64 result; // x0
  char *v4; // x19
  unsigned __int16 v5; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v6; // [xsp+8h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( (a2 & 1) != 0 )
  {
    v2 = a1 - 1196317000;
    if ( (unsigned int)(a1 - 1196317000) <= 4 )
    {
      v5 = 0;
      result = ghd_rm_get_vmid(v2, &v5);
      if ( !(_DWORD)result )
      {
        v4 = (char *)&gh_hvc_data + 2144 * v2;
        if ( (cancel_work_sync(v4 + 2112) & 1) != 0 )
          gh_hvc_put_work_fn((__int64)(v4 + 2112));
        result = gh_rm_console_flush(v5);
      }
    }
    else
    {
      result = 4294967274LL;
    }
  }
  else
  {
    result = 0;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
