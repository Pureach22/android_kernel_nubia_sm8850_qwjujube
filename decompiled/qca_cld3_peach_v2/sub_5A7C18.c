__int64 __usercall sub_5A7C18@<X0>(__int64 a1@<X0>, __int64 a2@<X1>, __int64 a3@<X3>, int a4@<W8>)
{
  int v4; // w23

  return wmi_extract_dbr_buf_cqi_metadata(a1, a2, a4 ^ (unsigned int)(v4 << 30), a3);
}
