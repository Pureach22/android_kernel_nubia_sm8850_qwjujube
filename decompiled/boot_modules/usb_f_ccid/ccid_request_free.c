_QWORD *__fastcall ccid_request_free(_QWORD *result, __int64 a2)
{
  _QWORD *v2; // x20

  if ( result )
  {
    v2 = result;
    kfree(*result);
    return (_QWORD *)usb_ep_free_request(a2, v2);
  }
  return result;
}
