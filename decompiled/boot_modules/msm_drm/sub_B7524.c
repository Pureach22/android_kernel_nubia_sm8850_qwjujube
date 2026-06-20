__int64 __usercall sub_B7524@<X0>(__int64 _X8@<X8>)
{
  __asm { SUBG            X28, X8, #0x370, #3 }
  return hfi_connector_get_cmd_buf();
}
