__int64 __fastcall qcom_flash_led_remove(__int64 result)
{
  __int64 *v1; // x8
  __int64 v2; // x9
  __int64 v3; // x10
  bool v4; // zf

  v1 = *(__int64 **)(result + 168);
  v2 = *v1;
  v3 = *((unsigned __int8 *)v1 + 140);
  if ( *((_BYTE *)v1 + 140) )
    v4 = *(_QWORD *)(*v1 + 8 * v3) == 0;
  else
    v4 = 1;
  if ( !v4 )
  {
    do
    {
      LOBYTE(v3) = v3 - 1;
      *((_BYTE *)v1 + 140) = v3;
    }
    while ( (_BYTE)v3 && *(_QWORD *)(v2 + 8LL * (unsigned __int8)v3) );
  }
  return result;
}
