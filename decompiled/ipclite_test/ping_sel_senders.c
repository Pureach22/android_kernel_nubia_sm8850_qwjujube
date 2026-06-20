__int64 __fastcall ping_sel_senders(__int64 result)
{
  __int64 v1; // x19

  v1 = result;
  if ( (qword_B680 & 0x200000000LL) != 0 )
  {
    result = ipclite_test_msg_send(1, result);
    if ( (qword_B680 & 0x400000000LL) == 0 )
    {
LABEL_3:
      if ( (qword_B680 & 0x800000000LL) == 0 )
        goto LABEL_4;
      goto LABEL_14;
    }
  }
  else if ( (qword_B680 & 0x400000000LL) == 0 )
  {
    goto LABEL_3;
  }
  result = ipclite_test_msg_send(2, v1);
  if ( (qword_B680 & 0x800000000LL) == 0 )
  {
LABEL_4:
    if ( (qword_B680 & 0x1000000000LL) == 0 )
      goto LABEL_5;
    goto LABEL_15;
  }
LABEL_14:
  result = ipclite_test_msg_send(3, v1);
  if ( (qword_B680 & 0x1000000000LL) == 0 )
  {
LABEL_5:
    if ( (qword_B680 & 0x2000000000LL) == 0 )
      goto LABEL_6;
    goto LABEL_16;
  }
LABEL_15:
  result = ipclite_test_msg_send(4, v1);
  if ( (qword_B680 & 0x2000000000LL) == 0 )
  {
LABEL_6:
    if ( (qword_B680 & 0x4000000000LL) == 0 )
      goto LABEL_7;
    goto LABEL_17;
  }
LABEL_16:
  result = ipclite_test_msg_send(5, v1);
  if ( (qword_B680 & 0x4000000000LL) == 0 )
  {
LABEL_7:
    if ( (qword_B680 & 0x8000000000LL) == 0 )
      goto LABEL_9;
    goto LABEL_8;
  }
LABEL_17:
  result = ipclite_test_msg_send(6, v1);
  if ( (qword_B680 & 0x8000000000LL) != 0 )
LABEL_8:
    result = ipclite_test_msg_send(7, v1);
LABEL_9:
  if ( (qword_B680 & 0x10000000000LL) != 0 )
    return ipclite_test_msg_send(8, v1);
  return result;
}
