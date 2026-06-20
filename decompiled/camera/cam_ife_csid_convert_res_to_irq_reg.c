__int64 __fastcall cam_ife_csid_convert_res_to_irq_reg(unsigned int a1)
{
  if ( a1 > 0xB )
    return 16;
  else
    return dword_44BD6C[a1];
}
