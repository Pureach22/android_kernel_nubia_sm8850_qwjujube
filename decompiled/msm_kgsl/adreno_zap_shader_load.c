__int64 __fastcall adreno_zap_shader_load(__int64 a1, __int64 a2)
{
  __int64 result; // x0

  if ( !a2 )
    return 0;
  if ( *(_DWORD *)(a1 + 20868) )
    return 0;
  result = kgsl_zap_shader_load(*(_QWORD *)(a1 + 11168) + 16LL);
  if ( !(_DWORD)result )
    *(_DWORD *)(a1 + 20868) = 1;
  return result;
}
