__int64 __fastcall qdf_flex_mem_init(__int64 result)
{
  int v1; // w8
  __int64 v2; // x19
  unsigned int v3; // w20

  v1 = *(unsigned __int16 *)(result + 40);
  *(_DWORD *)(result + 24) = 0;
  *(_QWORD *)(result + 32) = 0;
  if ( v1 )
  {
    v2 = result;
    v3 = 0;
    do
    {
      result = qdf_flex_mem_seg_alloc(v2);
      ++v3;
    }
    while ( v3 < *(unsigned __int16 *)(v2 + 40) );
  }
  return result;
}
