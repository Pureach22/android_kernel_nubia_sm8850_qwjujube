__int64 __fastcall msm_vidc_session_command(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        __int64 a5,
        unsigned int a6,
        __int64 a7)
{
  unsigned int hfi_port; // w0

  hfi_port = get_hfi_port(a1, a3);
  return venus_hfi_session_command(a1, a2, 3, hfi_port, *(unsigned int *)(a1 + 332), a4, a5, a6, a7);
}
