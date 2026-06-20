__int64 __fastcall md_module_notify(__int64 a1, __int64 a2, _DWORD *a3)
{
  raw_spin_lock(&md_modules_lock);
  if ( !*a3 )
    md_module_process((__int64)a3);
  raw_spin_unlock(&md_modules_lock);
  return 0;
}
