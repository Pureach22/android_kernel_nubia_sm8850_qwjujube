bool __fastcall qcom_is_buffer_hlos_accessible(int a1)
{
  return (a1 & 0x40400000) != 0;
}
