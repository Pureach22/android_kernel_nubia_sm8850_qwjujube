__int64 __fastcall synx_enable_resources(__int64 a1, __int64 a2)
{
  if ( (unsigned int)(a1 - 1024) > 0xBFF )
    return 0;
  else
    return synx_hwfence_enable_resources(a1, a2);
}
