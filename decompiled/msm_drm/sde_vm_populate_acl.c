__int64 __fastcall sde_vm_populate_acl(__int64 a1)
{
  __int64 result; // x0
  __int16 v2; // w9
  __int16 v3; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v4; // [xsp+8h] [xbp-8h]

  v4 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = 0;
  ghd_rm_get_vmid(a1, &v3);
  result = _kmalloc_cache_noprof(_mutex_init, 3520, 8);
  if ( result )
  {
    v2 = v3;
    *(_DWORD *)result = 1;
    *(_WORD *)(result + 4) = v2;
    *(_BYTE *)(result + 6) = 6;
  }
  else
  {
    result = 12;
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
