switch (signum(maxheap.size(), minheap.size()))
        {
            case 0 : if (x > median)
                    {
                        minheap.push(x);
                        median=minheap.top();
                    }
                    else
                    {
                        maxheap.push(x);
                        median=maxheap.top();
                    }
                    break;
            case 1 : if (x > median)
                    {
                        minheap.push(x);
                        median=(minheap.top()+maxheap.top())/2;
                    }
                    else
                    {
                        minheap.push(maxheap.top());
                        maxheap.pop();
                        maxheap.push(x);
                        median=(minheap.top()+maxheap.top())/2;
                    }
                    break;
            case -1 : if (x > median)
                    {
                        maxheap.push(minheap.top());
                        minheap.pop();
                        minheap.push(x);
                        median=(minheap.top()+maxheap.top())/2;
                    }
                    else
                    {
                        maxheap.push(x);
                        median=(minheap.top()+maxheap.top())/2;
                    }
                    break;
        }
