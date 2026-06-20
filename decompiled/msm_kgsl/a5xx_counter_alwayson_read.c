__int64 __fastcall a5xx_counter_alwayson_read(__int64 a1, __int64 *a2, unsigned int a3)
{
  __int64 v3; // x20

  v3 = *a2;
  return *(_QWORD *)(v3 + 48LL * a3 + 32) + a5xx_read_alwayson(a1);
}
