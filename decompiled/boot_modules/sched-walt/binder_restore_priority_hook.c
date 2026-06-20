void __fastcall binder_restore_priority_hook(__int64 a1, __int64 a2, char *a3)
{
  _DWORD *v3; // x8

  if ( a2 && (walt_disabled & 1) == 0 )
  {
    v3 = &vendor_data_pad;
    if ( a3 != (char *)&init_task )
      v3 = a3 + 5184;
    if ( v3[46] == 3 )
      v3[46] = *(_QWORD *)(a2 + 176);
  }
}
