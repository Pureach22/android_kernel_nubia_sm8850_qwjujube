__int64 __fastcall hw_fence_utils_get_skip_fctl_ref(__int64 a1, unsigned int a2)
{
  __int64 v2; // x30
  __int64 v3; // x8

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 60) > a2 )
    {
      v3 = *(_QWORD *)(*(_QWORD *)(a1 + 40) + 16LL * (int)a2);
      if ( v3 )
        return *(unsigned __int8 *)(v3 + 49);
    }
  }
  printk(&unk_2327D, "hw_fence_utils_get_skip_fctl_ref", 1937, v2, a2);
  return 0;
}
