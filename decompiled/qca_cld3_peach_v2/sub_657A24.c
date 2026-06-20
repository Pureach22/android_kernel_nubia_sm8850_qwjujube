__int64 __fastcall sub_657A24(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v8; // x3

  __asm { LDLAR           W3, [X16] }
  v8 = _OFF;
  __asm { LDLAR           W3, [X16] }
  return dp_mon_desc_pool_init(a1, a2, a3, v8);
}
