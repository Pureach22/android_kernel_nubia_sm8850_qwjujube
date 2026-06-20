__int64 __fastcall sde_hw_sspp_setup_img_size(__int64 result, __int64 a2)
{
  if ( result )
    return sde_reg_write(
             result,
             *(_DWORD *)(*(_QWORD *)(*(_QWORD *)(result + 56) + 48LL) + 72LL) + 4,
             *(_DWORD *)(a2 + 4),
             "SSPP_SRC_IMG_SIZE + idx");
  return result;
}
