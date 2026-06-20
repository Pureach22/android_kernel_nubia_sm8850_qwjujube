__int64 __fastcall dot11f_unpack_tdls_dis_req(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6,
        __int64 a7,
        __int64 a8)
{
  return unpack_core(a1, a2, a3, &FFS_TDLSDisReq, &IES_TDLSDisReq, a4, a5, a8);
}
