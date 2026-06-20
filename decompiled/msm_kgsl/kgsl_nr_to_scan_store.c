__int64 __fastcall kgsl_nr_to_scan_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // x0

  LODWORD(result) = kstrtouint(a3, 0, &kgsl_nr_to_scan);
  if ( (_DWORD)result )
    return (int)result;
  else
    return a4;
}
