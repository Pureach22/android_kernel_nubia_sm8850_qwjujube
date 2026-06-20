__int64 __fastcall sub_5AC50C(__int64 a1, __int64 a2, __int64 a3)
{
  __asm { PRFM            #0x19, [X11,#0x1E30] }
  return lim_process_ndi_mlm_add_bss_rsp(a1, a2, a3);
}
