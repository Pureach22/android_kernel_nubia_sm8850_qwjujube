__int64 __fastcall loopback_store(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  if ( (unsigned int)kstrtoint(a3, 0, *(_QWORD *)(a1 + 152) + 912LL) )
  {
    dev_err(a1, "Invalid input\n");
    return -22;
  }
  return a4;
}
